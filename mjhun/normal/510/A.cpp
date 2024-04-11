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
#define mset(x,a) (memset((x),(a),sizeof(x)))
#define mcpy(x,y) (memcpy((x),(y),sizeof(x)))
using namespace std;
typedef long long ll;

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    fore(i,0,n){
        fore(j,0,m){
            if(i%2==0||i%4==1&&j==m-1||i%4==3&&j==0)putchar('#');
            else putchar('.');
        }
        puts("");
    }
	return 0;
}