#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
#include<cassert>
#include<cstring>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<string>
using namespace std;
typedef pair<int,int>pint;
typedef vector<int>vint;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

char fld[10][10];

int main(){

    rep(i,8)scanf("%s",fld[i]);

    int minA=1001001001,minB=1001001001;

    rep(i,8)rep(j,8){
        if(fld[i][j]=='W'){
            bool f=true;
            for(int k=i-1;k>=0;k--)if(fld[k][j]!='.')f=false;
            if(f)chmin(minA,i);
        }
        else if(fld[i][j]=='B'){
            bool f=true;
            for(int k=i+1;k<8;k++)if(fld[k][j]!='.')f=false;
            if(f)chmin(minB,7-i);
        }
    }

    if(minA<=minB)cout<<"A"<<endl;
    else cout<<"B"<<endl;
    return 0;
}