#include<cstdio>
const int N=2002;
int n,k,i,j,s1[N][N],s2[N][N],ans;
int pu[N][N],pl[N][N],A[N],B[N];
bool a[N][N];
char c[N][N];
int max(int x,int y){
	return x>y?x:y;
}
int main(){
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)
        scanf("%s",c[i]+1);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            a[i][j]=c[i][j]=='B';
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++){
            s1[i][j]=s1[i-1][j]+a[i][j];
            s2[i][j]=s2[i][j-1]+a[i][j];
        }
    for(i=k;i<=n;i++)
        for(j=1;j<=n;j++)
            pu[i][j]=pu[i][j-1]+(s1[n][j]-s1[i][j]==0&&s1[i-k][j]==0);
    for(i=1;i<=n;i++)
        for(j=k;j<=n;j++)
            pl[i][j]=pl[i-1][j]+(s2[i][n]-s2[i][j]==0&&s2[i][j-k]==0);
    for(i=1;i<=n;i++)
    	A[i]=A[i-1]+(s1[n][i]==0);
    for(i=1;i<=n;i++)
    	B[i]=B[i-1]+(s2[i][n]==0);
    for(i=k;i<=n;i++)
    	for(j=k;j<=n;j++){
    		ans=max(ans,A[j-k]+A[n]-A[j]+B[i-k]+B[n]-B[i]+pu[i][j]-pu[i][j-k]+pl[i][j]-pl[i-k][j]);
		}
    printf("%d",ans);
}