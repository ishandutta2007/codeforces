#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<vector>
#include<queue>

#define ff(i,a,b) for(int i=(a),_b=(b);i<=_b;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MAX=1e5+5,INF=1e9,mod=1e9+7;

int n,a[MAX];
int tree[MAX];

void maximize(int &a,int b)
{
    if(a<b) a=b;
}

void update(int x,int val)
{
    for(int i=x;i<=n;i+=i&-i) maximize(tree[i],val);
}

int get(int x)
{
    int res=0;
    for(int i=x;i>0;i-=i&-i) maximize(res,tree[i]);
    return res;
}

void init(void)
{
    cin>>n;
    ff(i,1,n) cin>>a[i];
}

void process(void)
{
    ff(i,1,n) update(a[i],get(a[i])+1);
    cout<<get(n);
}

int main(void)
{
    init();
    process();
    return 0;
}