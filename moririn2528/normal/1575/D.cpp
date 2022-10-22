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
#include<set>
#include<complex>
#include<numeric>
#include<functional>
#include<unordered_map>
#include<unordered_set>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,LL> LP;
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
template<typename T> ostream& operator<<(ostream& os,const vector<T>& v1){
    int n=v1.size();
    for(int i=0;i<n;i++){
        if(i)os<<" ";
        os<<v1[i];
    }
    return os;
}
template<typename T1,typename T2> ostream& operator<<(ostream& os,const pair<T1,T2>& p){
    os<<p.first<<" "<<p.second;
    return os;
}
template<typename T> istream& operator>>(istream& is,vector<T>& v1){
    int n=v1.size();
    for(int i=0;i<n;i++)is>>v1[i];
    return is;
}
template<typename T1,typename T2> istream& operator>>(istream& is,pair<T1,T2>& p){
    is>>p.first>>p.second;
    return is;
}

namespace sol{
    bool check(char ca,int x){
        return ca=='_' || ca=='0'+x;
    }

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        string sa,sb;
        cin>>sa;
        n=sa.size();
		if(sa.size()==1){
			if(sa=="0" || sa=="X" || sa=="_")cout<<1<<endl;
			else cout<<0<<endl;
			return;
		}
        int s=0;
        for(i=0;i<10;i++){
            sb=sa;
            bool flag=false;
            for(j=0;j<sa.size();j++){
                if(sb[j]=='X')sb[j]='0'+i,flag=true;
            }
            if(!flag && i)break;
            if(sb[0]=='0')continue;
            a=1,b=0;
            for(j=0;j+2<sa.size();j++){
                if(sb[j]!='_')continue;
                if(j==0)a*=9;
                else a*=10;
            }
            for(j=0;j<100;j+=25){
                if(j==0 && n==2)continue;
                if(check(sb[n-2],j/10) && check(sb[n-1],j%10))b++;
            }
            s+=a*b;
        }
        cout<<s<<endl;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    sol::solve();
}