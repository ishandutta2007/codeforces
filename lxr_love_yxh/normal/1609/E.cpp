#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+10;
int n,q;
string s;
int nxt[12][12];
int mp[32],msk[12];
inline void ad(int a,int b){msk[a]=b;mp[b]=a;}
bool chk(int s,int t){return (s&t)?1:0;}
void init(){
	memset(msk,-1,sizeof(msk));
	memset(mp,-1,sizeof(mp));
	ad(0,1);ad(1,2);ad(2,4);//a b c
	ad(3,3);ad(4,3+(1<<3));//a,b x ab
	ad(5,5);//a,c
	ad(6,6);ad(7,6+(1<<4));//b,c x bc
	ad(8,7);ad(9,7+(1<<3));ad(10,7+(1<<4));ad(11,7+(1<<3)+(1<<4));//a,b,c x ab bc ab,bc
	for(int i=0;i<12;i++)for(int j=0;j<12;j++){
		int s1=msk[i],s2=msk[j];
		int s=0;bool ok=true;
		if(chk(s1,1)|chk(s2,1))s+=1;
		if(chk(s1,2)|chk(s2,2))s+=2;
		if(chk(s1,4)|chk(s2,4))s+=4;
		if(chk(s1,1)&chk(s2,(1<<4)))ok=false;
		if(chk(s1,(1<<3))&chk(s2,4))ok=false;
		if(chk(s1,1)&chk(s2,2))s+=1<<3;
		else if(chk(s1,1<<3)|chk(s2,1<<3))s+=1<<3;
		if(chk(s1,2)&chk(s2,4))s+=1<<4;
		else if(chk(s1,1<<4)|chk(s2,1<<4))s+=1<<4;
	//	cerr<<s1<<" "<<s2<<" "<<s<<" "<<mp[s]<<" ok="<<ok<<endl;
	//	if(mp[s]==-1)cerr<<s1<<" "<<s2<<" "<<s<<endl;
		if(ok)nxt[i][j]=mp[s];
		else nxt[i][j]=-1;
	}
//	for(int i=0;i<12;i++){
//		for(int j=0;j<12;j++)cerr<<nxt[i][j]<<" ";
//		cerr<<endl;
//	}
}
int ts[100010<<2][12];
inline void pu(int x){
	for(int i=0;i<12;i++)ts[x][i]=inf;
	for(int i=0;i<12;i++){
		if(ts[x<<1][i]==inf)continue;
		for(int j=0;j<12;j++){
			if(nxt[i][j]==-1||ts[x<<1|1][j]==inf)continue;
			ts[x][nxt[i][j]]=min(ts[x][nxt[i][j]],ts[x<<1][i]+ts[x<<1|1][j]);
		}
	}
}
void build(int x,int l,int r){
	if(l==r){
		for(int i=0;i<12;i++)ts[x][i]=inf;
		for(int i=0;i<3;i++){
			int w=1;
			if(i==0&&s[l]=='a')w=0;
			if(i==1&&s[l]=='b')w=0;
			if(i==2&&s[l]=='c')w=0;
			ts[x][mp[1<<i]]=w;
		}
		return;
	}
	int mid=(l+r)>>1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
	pu(x);
//	cerr<<x<<" "<<l<<" "<<r<<"\n";
//	for(int i=0;i<12;i++)cerr<<ts[x][i]<<" ";cerr<<endl;
}
void upd(int x,int l,int r,int pos,char c){
	if(l==r){
		for(int i=0;i<12;i++)ts[x][i]=inf;
		s[l]=c;
		for(int i=0;i<3;i++){
			int w=1;
			if(i==0&&s[l]=='a')w=0;
			if(i==1&&s[l]=='b')w=0;
			if(i==2&&s[l]=='c')w=0;
			ts[x][mp[1<<i]]=w;
		}
		return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid)upd(x<<1,l,mid,pos,c);
	else upd(x<<1|1,mid+1,r,pos,c);
	pu(x);
//	cerr<<"x="<<x<<" l="<<l<<" r="<<r<<endl;
//	for(int i=0;i<12;i++)cerr<<ts[x][i]<<" ";cerr<<endl;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	init();
	cin>>n>>q>>s;
	build(1,0,n-1);
	for(int i=0;i<q;i++){
		int pos;char c;
		cin>>pos>>c;
		pos--;
		upd(1,0,n-1,pos,c);
		int ans=inf;
		for(int s=0;s<12;s++)ans=min(ans,ts[1][s]);
		cout<<ans<<endl;
	}
	return 0;
}
/*inline? ll or int? size? min max?*/