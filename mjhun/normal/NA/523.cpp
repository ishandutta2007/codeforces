#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define mset(a,b) memset((a),(b),sizeof(a))
#define mcpy(a,b) memcpy((a),(b),sizeof(a))
using namespace std;
typedef long long ll;

map<pair<int,int>,int> w;
int n;
pair<int,int> r[200005];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int main(){
    scanf("%d",&n);
    fore(i,0,n){
        int x,y;
        scanf("%d%d",&x,&y);
        w[mp(x,y)]=i;
    }
    queue<pair<pair<int,int>,pair<int,int> > > q;
    for(auto p:w){
        int x=p.fst.fst,y=p.fst.snd;
        fore(_,0,4){
            int xx=x+dx[_],yy=y+dy[_];
            if(!w.count(mp(xx,yy)))q.push(mp(mp(xx,yy),mp(xx,yy)));
        }
    }
    while(!q.empty()){
        auto p=q.front().fst,asd=q.front().snd;q.pop();
        int x=p.fst,y=p.snd;
        fore(_,0,4){
            int xx=x+dx[_],yy=y+dy[_];
            if(w.count(mp(xx,yy))){
                r[w[mp(xx,yy)]]=asd;
                w.erase(mp(xx,yy));
                q.push(mp(mp(xx,yy),asd));
            }
        }
    }
    fore(i,0,n)printf("%d %d\n",r[i].fst,r[i].snd);
	return 0;
}