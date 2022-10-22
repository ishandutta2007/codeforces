#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<deque>
#include<iomanip>
#include<tuple>
#include<cassert>
#include<bitset>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,int> LP;
const int INF=1<<30;
const LL MAX=1e9+7;

void array_show(int *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%d%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(LL *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%lld%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(vector<int> &vec_s,int vec_n=-1,char middle=' '){
	if(vec_n==-1)vec_n=vec_s.size();
	for(int i=0;i<vec_n;i++)printf("%d%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}
void array_show(vector<LL> &vec_s,int vec_n=-1,char middle=' '){
	if(vec_n==-1)vec_n=vec_s.size();
	for(int i=0;i<vec_n;i++)printf("%lld%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}

const int N=160;

class Matrix{
private:
	bitset<N> ba[N],bb[N];
public:
	Matrix(){}

	Matrix(vector<vector<int>>& v1){
		int i,j;
		for(i=0;i<v1.size();i++){
			for(j=0;j<v1[i].size();j++){
				ba[i][j]=v1[i][j],bb[j][i]=v1[i][j];
			}
		}
	}

	bool get(int i,int j){
		return ba[i][j];
	}

	void print(int n){
		int i,j;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				cout<<ba[i][j];
			}
			cout<<endl;
		}
		cout<<endl;
	}

	Matrix operator *(Matrix obj){
		Matrix s;
		bitset<N> bt;
		int i,j,k;
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				bt=(this->ba[i])&obj.bb[j];
				if(bt.any())k=1;
				else k=0;
				s.ba[i][j]=k,s.bb[j][i]=k;
			}
		}
		return s;
	}

	void operator *=(Matrix obj){
		*this=(*this)*obj;
	}

	Matrix operator +(Matrix obj){
		Matrix s;
		for(int i=0;i<N;i++){
			s.ba[i]=(this->ba[i])|obj.ba[i];
		}
		for(int i=0;i<N;i++){
			s.bb[i]=(this->bb[i])|obj.bb[i];
		}
		return s;
	}

	void operator +=(Matrix obj){
		*this=(*this)+obj;
	}
	
	Matrix operator =(Matrix obj){
		for(int i=0;i<N;i++){
			this->ba[i]=obj.ba[i];
		}
		for(int i=0;i<N;i++){
			this->bb[i]=obj.bb[i];
		}
		return (*this);
	}
};

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	vector<tuple<int,int,int>> v1;
	cin>>n>>m;
	for(i=0;i<m;i++){
		cin>>a>>b>>c;
		a--,b--;
		v1.push_back(make_tuple(c,a,b));
	}
	sort(v1.begin(),v1.end());
	if(get<0>(v1[0])!=0){
		cout<<"Impossible"<<endl;
		return 0;
	}
	vector<vector<int>> va(n,vector<int>(n));
	vector<vector<int>> vb(n,vector<int>(n));
	vector<Matrix> v2;
	for(i=0;i<n;i++){
		vb[i][i]=1;
	}
	Matrix ma(vb),mb,mc;
	for(i=0;i<m;i++){
		tie(a,b,c)=v1[i];
		va[b][c]=1;
		vb[b][c]=1;
		if(i==m-1)a=n*2;
		else a=get<0>(v1[i+1])-a;
		Matrix m1(vb),m2(vb),m3;
		v2.clear();
		for(j=0;(1<<j)<=a;j++){
			v2.push_back(m1);
			m1*=m1;
		}
		b=0;
		m2=ma;
		for(j--;j>=0;j--){
			if(b+(1<<j)>a)continue;
			m3=m2*v2[j];
			if(!m3.get(0,n-1))m2=m3,b+=1<<j;
		}
		if(b!=a){
			b+=get<0>(v1[i])+1;
			cout<<b<<endl;
			return 0;
		}
		Matrix m4(va);
		for(j=0;(1<<j)<=a;j++){
			if((1<<j)&a)ma*=m4;
			m4*=m4;
		}
	}
	cout<<"Impossible"<<endl;
}