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

long long N;

int main(){
    scanf("%lld",&N);

    printf("%lld\n",(N-2)*(N-2));
    return 0;
}