#include<cstdio>
#include<vector>
using namespace std;

vector<int>a[301][301],b[301][301];
char s[100002];
int flag;
int ans,x1[400001],y1[400001],x2[400001],y2[400001];
void mv(int _x1,int _y1,int _x2,int _y2){
	if(flag)swap(_x1,_y1),swap(_x2,_y2);
	ans++;
	x1[ans]=_x1;
	y1[ans]=_y1;
	x2[ans]=_x2;
	y2[ans]=_y2;
}
int l[301],r[301],ll[301],rr[301];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	if(n>m)swap(n,m),flag=1;
	if(flag){
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++){
				scanf("%s",s);
				for(int k=0;s[k];k++)
					a[j][i].push_back(s[k]-'0');
			}
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++){
				scanf("%s",s);
				for(int k=0;s[k];k++)
					b[j][i].push_back(s[k]-'0');
			}
	}
	else{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				scanf("%s",s);
				for(int k=0;s[k];k++)
					a[i][j].push_back(s[k]-'0');
			}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				scanf("%s",s);
				for(int k=0;s[k];k++)
					b[i][j].push_back(s[k]-'0');
			}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			for(int k=a[i][j].size()-1;k>=0;k--)
				if(a[i][j][k]==0)
					mv(i,j,j==1?i==1?2:i-1:i,1),
					l[j==1?i==1?2:i-1:i]++;
				else mv(i,j,j==m?i==1?2:i-1:i,m),
					r[j==m?i==1?2:i-1:i]++;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=0;k<b[i][j].size();k++){
				if(b[i][j][k]==0)ll[i]++;
				else rr[i]++;
			}
	if(m==2){
		swap(ll[1],ll[2]);
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				while(l[i]<ll[i]&&l[j]>ll[j])mv(j,1,i,1),l[i]++,l[j]--;
				while(l[i]>ll[i]&&l[j]<ll[j])mv(i,1,j,1),l[i]--,l[j]++;
				while(r[i]<rr[i]&&r[j]>rr[j])mv(j,m,i,m),r[i]++,r[j]--;
				while(r[i]>rr[i]&&r[j]<rr[j])mv(i,m,j,m),r[i]--,r[j]++;
			}
		for(int i=2;i;i--)
			for(int k=b[1][i].size()-1;k>=0;k--)
				if(b[1][i][k]==0)mv(2,1,1,1);
				else mv(1,2,1,1);
		for(int i=2;i;i--)
			for(int k=b[2][i].size()-1;k>=0;k--)
				if(b[2][i][k]==0)mv(1,1,2,1);
				else mv(2,2,2,1);
		for(int i=1;i<=2;i++)
			for(int k=0;k<b[i][2].size();k++)
				mv(i,1,i,2);
	}
	else{
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				while(l[i]<ll[i]&&l[j]>ll[j])mv(j,1,i,1),l[i]++,l[j]--;
				while(l[i]>ll[i]&&l[j]<ll[j])mv(i,1,j,1),l[i]--,l[j]++;
				while(r[i]<rr[i]&&r[j]>rr[j])mv(j,m,i,m),r[i]++,r[j]--;
				while(r[i]>rr[i]&&r[j]<rr[j])mv(i,m,j,m),r[i]--,r[j]++;
			}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)if(j!=2)
				for(int k=b[i][j].size()-1;k>=0;k--)
					if(b[i][j][k]==0)mv(i,1,i,2);
					else mv(i,m,i,2);
			for(int k=b[i][2].size()-1;k>=0;k--)
				if(b[i][2][k]==0)mv(i,1,i,2);
				else mv(i,m,i,2);
			for(int j=1;j<=m;j++)if(j!=2)
				for(int k=0;k<b[i][j].size();k++)
					mv(i,2,i,j);
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=ans;i++){
		printf("%d %d %d %d\n",x1[i],y1[i],x2[i],y2[i]);
/*		if(flag)swap(x1[i],y1[i]),swap(x2[i],y2[i]);
		a[x2[i]][y2[i]].push_back(0);
		for(int j=a[x2[i]][y2[i]].size()-1;j;j--)
			a[x2[i]][y2[i]][j]=a[x2[i]][y2[i]][j-1];
		a[x2[i]][y2[i]][0]=a[x1[i]][y1[i]][a[x1[i]][y1[i]].size()-1];
		a[x1[i]][y1[i]].pop_back();
*/	}
/*	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			for(int k=0;k<a[i][j].size();k++)
				printf("%d",a[i][j][k]);
			printf(" ");
		}*/
}