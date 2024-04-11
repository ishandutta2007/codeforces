#include <cstdio>
#include <iostream>
#include <set>
#define mp make_pair
#define fst first
#define snd second
using namespace std;

int n;
multiset<pair<pair<int,int>,int> > s;
int sol[1024];

int main(){
    int i;
    scanf("%d",&n);
    for(i=0;i<n;++i){
        int l,r;
        scanf("%d %d",&l,&r);
        s.insert(mp(mp(l,r),i));
    }
    while(!s.empty()){
        multiset<pair<pair<int,int>,int> >::iterator it=s.begin();
        int k=(it->fst).fst;
        sol[it->snd]=k;
        s.erase(s.begin());
        it=s.begin();
        while((it->fst).fst==k){
            int h=(it->fst).snd,g=it->snd;
            s.erase(it);
            s.insert(mp(mp(k+1,h),g));
            it=s.begin();
        }
    }
    printf("%d",sol[0]);
    for(i=1;i<n;++i){
        printf(" %d",sol[i]);
    }
    putchar('\n');
    return 0;
}