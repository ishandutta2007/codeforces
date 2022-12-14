#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
#define mo 1000000007
#define N 100005
int read(){
	char ch=getchar();int x=0,f=1;
	while(ch<'0'||ch>'9') f=ch=='-'?-f:f,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int ab(int x){return x>0?x:-x;}
int n,m,x[N],y[N],used[N],s[N];
struct node{
	int s0,s1;
}ans=(node){1,0},dp0,dp1,dd0,dd1,temp;
node operator+(node a,node b){
	return (node){(a.s0+b.s0)%mo,(a.s1+b.s1)%mo};
}
node operator*(node a,node b){
	return (node){(1ll*a.s0*b.s0+1ll*a.s1*b.s1)%mo,(1ll*a.s0*b.s1+1ll*a.s1*b.s0)%mo};
}
int cir,el,er,len,sign[N];
int main(){
	n=read();m=read();
	rep(i,1,m) s[i]=0;
	rep(i,1,n){
		x[i]=read();
		if(x[i]==1) x[i]=0;
		else x[i]=read(),s[ab(x[i])]+=i;
		y[i]=read();s[ab(y[i])]+=i;
		used[i]=0;
	}
	//for chain
	rep(i,1,n) if(!used[i]){
		if(ab(x[i])==ab(y[i])){
			if(x[i]==y[i]) ans=ans*(node){1,1};
			else ans=ans*(node){0,2};
			used[i]=1;
			continue;
		}
		len=0;cir=el=er=0;
		int p=i,q=ab(x[p]);
		if(q&&s[q]!=p) q=ab(y[p]);
		if(q&&s[q]!=p) continue;
		used[i]=1;
		//if(!x[p]) printf("%d",y[p]);
		//else printf("(%d|%d)",x[p],y[p]);
		if(x[p]) el=1;
		while(1){
			q=ab(x[p])+ab(y[p])-q;
			sign[len+1]=ab(x[p])==q?x[p]:y[p];
			p=s[q]-p;
			if(used[p]){
				len++;
				sign[len]/=ab(x[p])==q?x[p]:y[p];
				cir=1;p=0;
			}
			if(!p) break;
			used[p]=1;
			len++;
			sign[len]/=ab(x[p])==q?x[p]:y[p];
			if(!x[p]) break;
			//printf("^(%d|%d)",x[p],y[p]);
		}
		//if(p) printf("^%d",y[p]);
		if(!p) er=1;
		//puts("");
		//printf("%d %d %d %d:",cir,el,er,len);
		//rep(i,1,len) printf(i<len?"%d ":"%d\n",sign[i]);
		if(cir){
			temp=(node){0,0};
			//consider start 0
			dp0=(node){1,0};dp1=(node){0,1};
			rep(i,2,len){
				if(sign[i]==-1) std::swap(dp0,dp1);
				if(i<len){
					dd0=dp0+(dp1*(node){0,1});dd1=(dp1+dp0)*(node){0,1};
					dp0=dd0;dp1=dd1;
				}
				else{
					dp1=dp1*(node){0,1};
					if(sign[1]==-1) dp0=dp0*(node){0,1};
				}
			}
			temp=temp+(dp0+dp1);
			//consider start 1
			dp0=(node){0,1};dp1=(node){0,1};
			rep(i,2,len){
				if(sign[i]==-1) std::swap(dp0,dp1);
				if(i<len){
					dd0=dp0+(dp1*(node){0,1});dd1=(dp1+dp0)*(node){0,1};
					dp0=dd0;dp1=dd1;
				}
				else{
					dp1=dp1*(node){0,1};
					if(sign[1]==1) dp0=dp0*(node){0,1};
				}
			}
			temp=temp+(dp0+dp1);
			ans=ans*temp;
		}
		else{
			if(el) dp0=(node){1,1},dp1=(node){0,2};
			else dp0=(node){1,0},dp1=(node){0,1};
			rep(i,1,len){
				if(sign[i]==-1) std::swap(dp0,dp1);
				if(i<len||er){
					dd0=dp0+(dp1*(node){0,1});dd1=(dp1+dp0)*(node){0,1};
					dp0=dd0;dp1=dd1;
				}
			}
			if(!er) dp1=dp1*(node){0,1};
			ans=ans*(dp0+dp1);
		}
	}
	//for circle
	rep(i,1,n) if(!used[i]){
		used[i]=1;
		if(ab(x[i])==ab(y[i])){
			if(x[i]==y[i]) ans=ans*(node){1,1};
			else ans=ans*(node){0,2};
			continue;
		}
		len=0;cir=el=er=0;
		int p=i,q=ab(x[p]);
		//if(!x[p]) printf("%d",y[p]);
		//else printf("(%d|%d)",x[p],y[p]);
		if(x[p]) el=1;
		while(1){
			q=ab(x[p])+ab(y[p])-q;
			sign[len+1]=ab(x[p])==q?x[p]:y[p];
			p=s[q]-p;
			if(used[p]){
				len++;
				sign[len]/=ab(x[p])==q?x[p]:y[p];
				cir=1;p=0;
			}
			if(!p) break;
			used[p]=1;
			len++;
			sign[len]/=ab(x[p])==q?x[p]:y[p];
			if(!x[p]) break;
			//printf("^(%d|%d)",x[p],y[p]);
		}
		//if(p) printf("^%d",y[p]);
		if(!p) er=1;
		//puts("");
		//printf("%d %d %d %d:",cir,el,er,len);
		//rep(i,1,len) printf(i<len?"%d ":"%d\n",sign[i]);
		if(cir){
			temp=(node){0,0};
			//consider start 0
			dp0=(node){1,0};dp1=(node){0,1};
			rep(i,2,len){
				if(sign[i]==-1) std::swap(dp0,dp1);
				if(i<len){
					dd0=dp0+(dp1*(node){0,1});dd1=(dp1+dp0)*(node){0,1};
					dp0=dd0;dp1=dd1;
				}
				else{
					dp1=dp1*(node){0,1};
					if(sign[1]==-1) dp0=dp0*(node){0,1};
				}
			}
			temp=temp+(dp0+dp1);
			//consider start 1
			dp0=(node){0,1};dp1=(node){0,1};
			rep(i,2,len){
				if(sign[i]==-1) std::swap(dp0,dp1);
				if(i<len){
					dd0=dp0+(dp1*(node){0,1});dd1=(dp1+dp0)*(node){0,1};
					dp0=dd0;dp1=dd1;
				}
				else{
					dp1=dp1*(node){0,1};
					if(sign[1]==1) dp0=dp0*(node){0,1};
				}
			}
			temp=temp+(dp0+dp1);
			ans=ans*temp;
		}
		else{
			if(el) dp0=(node){1,1},dp1=(node){0,2};
			else dp0=(node){1,0},dp1=(node){0,1};
			rep(i,1,len){
				if(sign[i]==-1) std::swap(dp0,dp1);
				if(i<len||er){
					dd0=dp0+(dp1*(node){0,1});dd1=(dp1+dp0)*(node){0,1};
					dp0=dd0;dp1=dd1;
				}
			}
			if(!er) dp1=dp1*(node){0,1};
			ans=ans*(dp0+dp1);
		}
	}
	rep(i,1,m) if(!s[i]) ans=ans*(node){2,0};
	printf("%d\n",ans.s1);
}