#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll c2(int x){
    return ((ll)x*(x-1))/2;
}

vector<pair<int,int> > g[100005]; // nodohijo-arista
int n,l[100005],w[100005],h[100005]; // nodo de arista, cuantos dbjo de nodo

void dfs(int v,int f){
    h[v]=1;
    for(int i=0;i<g[v].size();++i){
        int s=g[v][i].first,a=g[v][i].second;
        if(s!=f){
            w[a]=s;
            dfs(s,v);
            h[v]+=h[s];
        }
    }
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n-1;++i){
        int a,b;
        scanf("%d%d%d",&a,&b,l+i);a--;b--;
        g[a].push_back(make_pair(b,i));
        g[b].push_back(make_pair(a,i));
    }
    dfs(0,-1);
    double r=0.;ll t=(((ll)n)*(n-1)*(n-2))/6;
    for(int i=0;i<n-1;++i){
        int k=h[w[i]];
        r+=(double)((ll)l[i]*(c2(k)*(n-k)+c2(n-k)*k))/t;
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int j,x,k;
        scanf("%d%d",&j,&x);j--;
        k=h[w[j]];
        r+=(double)((ll)(x-l[j])*(c2(k)*(n-k)+c2(n-k)*k))/t;
        l[j]=x;
        printf("%.10lf\n",r*2);
    }
}