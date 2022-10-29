#include <algorithm>
#include <cstdio>
#include <vector>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
using namespace std;

int n;
int l[100005];
pair<int, int> ld[100005];
int s[100005];

vector<int> p[205];

int main(){
    scanf("%d", &n);
    for(int i=0;i<n;++i){
        scanf("%d",l+i);
    }
    for(int i=0;i<n;++i){
        int d;
        scanf("%d",&d);
        ld[i]=mp(l[i],d);
    }
    sort(ld,ld+n);
    s[n]=0;
    for(int i=0;i<n;++i){
        p[ld[i].snd].pb(ld[i].fst);
    }
    for(int i=n-1;i>=0;--i){
        s[i]=s[i+1]+ld[i].snd;
    }

    int i=0, r=1<<30;
    while(i<n){
        int k=ld[i].fst,j,m,q;
        for(j=i+1;j<n&&ld[j].fst==k;++j);
        m=n-2*(j-i)+1;
        m-=n-j;
        q=s[j];
        i=j;
        j=0;
        while(m>0){
            if(p[j].size()){
                int h=min((int)distance(p[j].begin(),lower_bound(p[j].begin(),p[j].end(),k)),m);
                m-=h;
                q+=h*j;
            }
            ++j;
        }
        r=min(r,q);
    }
    printf("%d\n",r);
    return 0;
}