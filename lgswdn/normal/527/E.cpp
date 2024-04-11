#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9;

struct edge {int to,nxt;}e[N*2]; int hd[N],tot=1;
void add(int u,int v) {e[++tot]=(edge){v,hd[u]};hd[u]=tot;}

int n,m,d[N],type,tick;
bool vst[N*2];

void write(int u) {
	for(int &i=hd[u],v;i;i=e[i].nxt) {
		if(vst[i]) continue; vst[i]=vst[i^1]=1;
		tick++;
		write(v=e[i].to);
		if((++type)&1) printf("%d %d\n",u,v);
		else printf("%d %d\n",v,u);
	}
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++)
		scanf("%d%d",&u,&v),
		add(u,v), add(v,u), d[u]++, d[v]++;
	vector<int>odd;
	for(int i=1;i<=n;i++) if(d[i]%2) odd.push_back(i);
	for(int i=0;i<odd.size();i+=2)
		m++, add(odd[i],odd[i+1]), add(odd[i+1],odd[i]);
	if(m&1) add(1,1), add(1,1), m++;
	printf("%d\n",m);
	write(1);
	return 0;
}