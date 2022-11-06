#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
namespace IO
{
    const int sz=1<<15;
    char inbuf[sz],outbuf[sz];
    char *pinbuf=inbuf+sz;
    char *poutbuf=outbuf;
    inline char _getchar()
    {
        if (pinbuf==inbuf+sz)fread(inbuf,1,sz,stdin),pinbuf=inbuf;
        return *(pinbuf++);
    }
    inline void _putchar(char x)
    {
        if (poutbuf==outbuf+sz)fwrite(outbuf,1,sz,stdout),poutbuf=outbuf;
        *(poutbuf++)=x;
    }
    inline void flush()
    {
        if (poutbuf!=outbuf)fwrite(outbuf,1,poutbuf-outbuf,stdout),poutbuf=outbuf;
    }
}
inline int read(){
	int v=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9'){
		v=v*10+c-'0';
		c=getchar();
	}
	return v*f;
}

const int Maxn=1005;
bool F[Maxn];
int main(){
	int n;
	scanf("%d",&n);
	if (n<=3){
		printf("0\n");
		fflush(stdout);
		return 0;
	}
	vector<int> V;
	int Mx=-1,B=2,CC=0;
	for (int Bl=2;Bl<=n;Bl++){
		int cb=n/Bl;
		cb--;
		int rem=n%Bl;
		int fuck=cb*(Bl-1);
		if (rem>=2) fuck+=rem-1;
		if (fuck>Mx){
			Mx=fuck;B=Bl;CC=cb;
		}
	}
	for (int i=1,_=0;_<=CC;_++,i+=B){
		for (int j=0;j<B-1;j++)V.pb(i+j);
	}
	int rem=n%B;
	if (rem>=2){
		for (int i=n-rem+1;i<=n-1;i++){
			V.pb(i);
		}
	}
	while (1){
		vector<int> t;
		for (int i=0;i<V.size();i++){
			if (!F[V[i]]){
				t.pb(V[i]);
			}
		}
		if (t.size()==B-1){
			printf("0\n");
			fflush(stdout);
			return 0;
		}
		printf("%d ",t.size());
		for (int i=0;i<t.size();i++) printf("%d ",t[i]),F[t[i]]=1;
		printf("\n");
		fflush(stdout);
		int x,k=t.size();
		scanf("%d",&x);
		for (int i=x,j=0;j<k;j++,i++){
			if (i>n) i=1;
			F[i]=0;
		}
	}
}