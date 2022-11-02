# include <iostream>
# include <cstdio>
# include <vector>
using namespace std;

const int N = 100010;
int s[N], v[N];

# define tr(i, c) for(__typeof(c.begin())\
    i=c.begin(); i!=c.end(); i++)
vector<int> g[N];

int calc(int e,int p){
    int &c = s[e]; c=1;
    tr(i,g[e]) if(*i!=p&&!v[*i])
        c += calc(*i, e);
    return c;
}

int best(int e,int c,int p){
    tr(i,g[e]) 
        if(*i!=p&&!v[*i]&&s[*i]>c/2)
            return best(*i, c, e);
    return e;
}

void f(int e,int cl){
    calc(e,-1); int k;
    k=best(e,s[e],-1);
    v[k]=cl+1;
    
    tr(i,g[k]) if(!v[*i])
        f(*i, cl+1);
}

int main(){
    int n, a, b;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    f(0,0);
    for(int i=0;i<n;i++)
        printf("%c ",v[i]+'A'-1);
    return 0;
}