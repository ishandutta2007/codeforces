#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<cmath>
#include<tuple>
#include<string>
#include<chrono>
#include<functional>
#include<iterator>
#include<random>
#include<unordered_set>
#include<array>
#include<map>
#include<iomanip>
#include<assert.h>
#include<list>
#include<bitset>
#include<stack>
#include<memory>
#include<numeric>
#include <utility>

using namespace std;
typedef long long int llint;
//#include <bits/stdc++.h>
using namespace std;
template<class T>
struct Matrix{
  vector<vector<T>> A;
  Matrix() {}
  Matrix(size_t n,size_t m):A(n,vector<T>(m,0)){}
  Matrix(size_t n) : A(n,vector<T>(n,0)){}
  inline const vector<T> &operator[](int k) const{
    return (A.at(k));
  }
  inline vector<T> &operator[](int k){
    return (A.at(k));
  }
  size_t height() const{
    return (A.size());
  }
  size_t width() const{
    return (A[0].size());
  }
};
template<typename T>
pair<T,vector<int>> hungarian(Matrix<T> &A){
  const T  infty = numeric_limits<T>::max();
  const int N = (int) A.height();
  const int M = (int) A.width();
  vector<int> P(M),way(M);
  vector<T> U(N,0),V(M,0),minV;
  vector<bool> used;
  for(int i = 1;i < N;i++){
    P[0] = i;
    minV.assign(M,infty);
    used.assign(M,false);
    int j0 = 0;
    while(P[j0] != 0){
      int i0 = P[j0],j1 = 0;
      used[j0] = true;
      T delta = infty;
      for(int j = 1;j < M;++j){
        if(used[j]) continue;
        T curr = A[i0][j] - U[i0] - V[j];
        if(curr < minV[j]) minV[j] = curr,way[j] = j0;
        if(minV[j] < delta) delta = minV[j],j1 = j;
      }
      for(int j = 0;j < M;j++){
        if(used[j]) U[P[j]] += delta,V[j] -= delta;
        else minV[j] -= delta;
      }
      j0 = j1;
    }
    do{
      P[j0] = P[way[j0]];
      j0 = way[j0];
    }while(j0 != 0);
  }
  return {-V[0],P};
}
int main(void){
	int n,d,i,j,k;cin>>d>>n;
	n++;
	vector<string>ban(n);
	vector<int>kaz(n);
		for(k=0;k<d;k++){ban[0].push_back('0');}
	for(i=1;i<n;i++){
		cin>>ban[i];
		for(k=0;k<d;k++){
			if(ban[i][k]=='1'){kaz[i]++;}
		}
	}
	Matrix<llint> in(n+1,n+1);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			//
			int can=1;
			if(i==j){can=0;}
			for(k=0;k<d;k++){
				if(ban[i][k]=='1'&&ban[j][k]=='0'){can=0;}
			}
			if(can){in[i+1][j+1]=kaz[j]-kaz[i];}
			else{in[i+1][j+1]=1+kaz[j];}
		}
	}
	auto ret=hungarian(in);
	//cerr<<"de"<<endl;
	//for(auto it:ret.second){cerr<<it<<endl;}
	vector<int>sta;
	vector<int>go(n);//
	for(i=0;i<n;i++){
		go[ret.second[i+1]-1]=i;
		if(in[ret.second[i+1]][i+1]!=kaz[i]-kaz[ret.second[i+1]-1]){
			sta.push_back(i);
		}
	}
	
	//cerr<<"ok"<<endl;
	//for(i=0;i<n;i++){cerr<<go[i]<<endl;}
	//cerr<<"sta="<<endl;
	//for(auto it:sta){cerr<<it<<endl;}
	vector<int>ans;
	int bas=0;
	
	vector<int>kta(n);
	kta[0]=1;
	for(i=0;i<n-1;i++){
		int nb=go[bas];
		if(kta[nb]==1){
			while(kta[sta.back()]==1){sta.pop_back();}
			nb=sta.back();
		}
		kta[nb]=1;
		//cerr<<"nb="<<nb<<endl;
		if(in[bas+1][nb+1]==kaz[nb]-kaz[bas]){
			//can
			for(k=0;k<d;k++){
				if(ban[bas][k]=='0'&&ban[nb][k]=='1'){
					ans.push_back(k);
				}
			}
		}else{
			ans.push_back(-1);
			for(k=0;k<d;k++){
				if(ban[nb][k]=='1'){
					ans.push_back(k);
				}
			}
		}
		bas=nb;
	}
	cout<<ans.size()<<endl;
	for(auto it:ans){
		if(it==-1){cout<<"R ";}
		else{cout<<it<<" ";}
	}
	cout<<endl;
}