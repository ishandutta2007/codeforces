#include<bits/stdc++.h>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(file) freopen(file".in","r",stdin)
#define fileout(file) freopen(file".out","w",stdout)

const int N=1e6+5;
int T,n,k;
char s[N],a[N],b[N];
int out[30],in[30],tout[30],tin[30];
int worka(int pos) {
	fr(i,pos,n) if(~out[s[i]]) {
		if(out[s[i]]<a[i]) return 0;
		if(out[s[i]]>a[i]) return 1;
	} else {
		rf(j,k-1,a[i]+1) if(in[j]==-1)
			return out[s[i]]=j,in[j]=s[i],1;
		if(~in[a[i]]) return 0;
		out[s[i]]=a[i]; in[a[i]]=s[i];
	}
	return 1;
}
int workb(int pos) {
	fr(i,pos,n) if(~out[s[i]]) {
		if(out[s[i]]>b[i]) return 0;
		if(out[s[i]]<b[i]) return 1;
	} else {
		rf(j,b[i]-1,0) if(in[j]==-1)
			return out[s[i]]=j,in[j]=s[i],1;
		if(~in[b[i]]) return 0;
		out[s[i]]=b[i]; in[b[i]]=s[i];
	}
	return 1;
}
int main() {
	scanf("%d",&T); while(T--) {
		scanf("%d%s%s%s",&k,s+1,a+1,b+1);
		n=strlen(s+1);
		fr(i,1,n) {
			s[i]-='a';
			a[i]-='a';
			b[i]-='a';
		}
		fo(i,0,k) in[i]=out[i]=-1;
		int ok=1;
		fr(i,1,n) if(a[i]==b[i]) {
			if((~out[s[i]]||~in[a[i]])&&out[s[i]]!=a[i]) {
				ok=0; break;
			}
			out[s[i]]=a[i]; in[a[i]]=s[i];
		} else if(~out[s[i]]) {
			if(a[i]<out[s[i]]&&out[s[i]]<b[i]) break;
			if(out[s[i]]==a[i]) ok=worka(i+1);
			else if(out[s[i]]==b[i]) ok=workb(i+1);
			else ok=0;
			break;
		} else {
			fr(j,a[i]+1,b[i]-1) if(in[j]==-1) {
				out[s[i]]=j; in[j]=s[i]; break;
			}
			if(~out[s[i]]) break;
			ok=0;
			if(in[a[i]]==-1) {
				fo(j,0,k) tout[j]=out[j],tin[j]=in[j];
				out[s[i]]=a[i]; in[a[i]]=s[i]; ok=worka(i+1);
				if(ok) break;
				fo(j,0,k) out[j]=tout[j],in[j]=tin[j];
			}
			if(in[b[i]]==-1) {
				fo(j,0,k) tout[j]=out[j],tin[j]=in[j];
				out[s[i]]=b[i]; in[b[i]]=s[i]; ok=workb(i+1);
				if(ok) break;
				fo(j,0,k) out[j]=tout[j],in[j]=tin[j];
			}
			break;
		}
		if(!ok) {
			cout<<"NO"<<endl;
			continue;
		}
		int pt=k-1;
		fo(i,0,k) if(out[i]==-1) {
			while(~in[pt]) --pt;
			out[i]=pt; in[pt]=i;
		}
		puts("YES");
		fo(i,0,k) putchar(out[i]+'a');
		puts("");
	}
	return 0;
}
int read() {
	static int x,c,f; x=0,f=1;
	do c=getchar(),(c=='-'&&(f=-1)); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}