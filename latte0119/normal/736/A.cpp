#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int table[1000];

int N;

signed main(){
    cin>>N;

    table[0]=1;
    table[1]=2;
    for(int i=2;i<1000;i++)table[i]=table[i-1]+table[i-2];
    int n=0;
    while(table[n]<=N)n++;
    cout<<n-1<<endl;
    return 0;
}