#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 200000
#define  MAXV 200000
int g[MAXV+10],n,s,k,t;
void Read(int &x){
	char c;
	while(c=getchar(),c!=EOF){
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return;
		}
	}
}
struct Car{
    int v, c;
    bool operator<(const Car& rhs)const{
        return v<rhs.v;
    }
}cars[MAXN+10];
bool check(int val){
    double ret = 0;
    for(int i=0;i<=k;i++){
        if(g[i+1] - g[i] > val)
            return false;
        ret += 2.0*(g[i+1]-g[i]);
        int oth = val-g[i+1]+g[i];
        if(oth > g[i+1]-g[i])
            ret -= 1.0*(g[i+1]-g[i]);
        else ret -= 1.0*oth;
    }
    return ret <= t;
}
int main(){
    Read(n),Read(k),Read(s),Read(t);
    for(int i=1;i<=n;i++)
        Read(cars[i].c),Read(cars[i].v);
    sort(cars+1, cars+1+n);
    for(int i=1;i<=k;i++)
       Read(g[i]);
    sort(g+1, g+1+k);
    g[k+1] = s;
    int l = 0, r = cars[n].v, ans = -1;
    while(l <= r){
        int mid = (l+r)>>1;
        if(check(mid)){
            ans = mid;
            r = mid-1;
        }else l = mid+1;
    }
    if(ans == -1){
        printf("-1\n");
        return 0;
    }
    int op = 0x3f3f3f3f;
    for(int i=n;i>=1;i--){
        if(cars[i].v < ans)
            break;
        op = min(op, cars[i].c);
    }
    printf("%d\n", op);

    return 0;
}