#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

struct dn{int c,z;}a[500001],b[500001];
int s1[500001],s2[500001];
int aa,bb;
int flag;
struct da{int x,y;};
vector<da>ans;
void jh(int u,int v){
	if(!flag)ans.push_back((da){s1[u],s2[v]});
	else ans.push_back((da){s2[v],s1[u]});
//	printf("%d!%d!%d!%d!%d %d %d %d %d %d\n",aa,bb,u,v,s1[1],s1[2],s1[3],s2[1],s2[2],s2[3]);
	flag^=1;
	dn x[10],y[10];
	int xx=0,yy=0;
	for(int i=u+1;i<=aa;i++)
		x[++xx]=a[i];
	for(int i=v+1;i<=bb;i++)
		y[++yy]=b[i];
	aa=u;
	bb=v;
	if(aa&&yy&&y[1].c==a[u].c)y[1].z+=a[u].z,aa--;
	if(bb&&xx&&x[1].c==b[v].c)x[1].z+=b[v].z,bb--;
	for(int i=1;i<=yy;i++)
		a[aa+1]=y[i],
		s1[aa+1]=s1[aa]+y[i].z,
		aa++;
	for(int i=1;i<=xx;i++)
		b[bb+1]=x[i],
		s2[bb+1]=s2[bb]+x[i].z,
		bb++;
}
void cl(){
	if(a[aa].c==b[bb].c){
		if(aa==2&&bb==2){
			jh(0,1);
			jh(1,1);
		}
		else if(aa==1&&bb==2){
			jh(1,1);
		}
		else if(aa==1&&bb==3){
			jh(1,2);
			jh(0,1);
		}
		else if(aa==2&&bb==1){
			jh(1,1);
		}
		else if(aa==3&&bb==1){
			jh(2,1);
			jh(1,0);
		}
	}
	else{
		if(aa==2&&bb==2){
			jh(1,1);
		}
		else if(aa==1&&bb==3){
			jh(1,1);
			jh(1,1);
		}
		else if(aa==1&&bb==2){
			jh(0,1);
		}
		else if(aa==3&&bb==1){
			jh(1,1);
			jh(1,1);
		}
		else if(aa==2&&bb==1){
			jh(1,0);
		}
	}
}
char aaa[1000010],bbb[1000010];
int main(){
	scanf("%s%s",aaa+1,bbb+1);
	for(int i=1;aaa[i];i++){
		int j=i;
		while(aaa[j+1]==aaa[i])j++;
		a[++aa]=(dn){aaa[i]=='b',j-i+1};
		i=j;
	}
	for(int i=1;bbb[i];i++){
		int j=i;
		while(bbb[j+1]==bbb[i])j++;
		b[++bb]=(dn){bbb[i]=='b',j-i+1};
		i=j;
	}
	for(int i=1;i<=aa;i++)
		s1[i]=s1[i-1]+a[i].z;
	for(int i=1;i<=bb;i++)
		s2[i]=s2[i-1]+b[i].z;
	if(aa==1){
		if(bb<=3)cl();
		else{
			int u=bb-3;
			if(b[u].c==a[1].c)
				jh(0,u);
			else jh(1,u);
		}
	}
	else if(bb==1){
		if(aa<=3)cl();
		else{
			int u=aa-3;
			if(a[u].c==b[1].c)jh(u,0);
			else jh(u,1);
		}
	}
	for(;;){
		if(aa+bb<=4){
			cl();
			break;
		}
		if(a[aa].c==b[bb].c){
			if(aa>bb)jh(aa-2,bb-1);
			else jh(aa-1,bb-2);
		}
		else{
			if(abs(aa-bb)<=1)jh(aa-1,bb-1);
			else if(aa>bb)jh(aa-3,bb-1);
			else jh(aa-1,bb-3);
		}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
		printf("%d %d\n",ans[i].x,ans[i].y);
}