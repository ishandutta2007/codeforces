#include<bits/stdc++.h>
#define re register
int a[200100],n,q,cnt,l[200100],r[200100],bl[200100],ans[200100],ll[257][257],*ll1[257],a1[200100];
int vx[2300100],vy[2300100];
const int B=256;
void dc(re int l,re int r,re int*a1,re int**ll)
{
	if(l==r){ll[1][1]=a1[1];return;}
	re int mid=(l+r)/2,ta1=0,ta2=0;
	int aa1[mid-l+2],aa2[r-mid+2],ll1[mid-l+2][mid-l+2],rr1[r-mid+2][r-mid+2],*lll[mid-l+2],*rrr[r-mid+2];
	for(re int i=1;i<=r-l+1;i++)if(a[a1[i]]<=mid)aa1[++ta1]=a1[i];else aa2[++ta2]=a1[i];
	for(re int i=1;i<=ta1;i++)lll[i]=ll1[i];
	for(re int i=1;i<=ta2;i++)rrr[i]=rr1[i];
	dc(l,mid,aa1,lll);
	dc(mid+1,r,aa2,rrr);
	re int i1=1,i2=1;
	for(re int i=1;i<=r-l+1;i++)
	{
		re int j1=i1-1,j2=i2-1;
		for(re int j=i;j<=r-l+1;j++)
		{
			if(a[a1[j]]<=mid)j1++;
			else j2++;
			if(i1>j1)ll[i][j]=rr1[i2][j2];
			else if(i2>j2)ll[i][j]=ll1[i1][j1];
			else
			{
				vx[++cnt]=ll1[i1][j1];vy[cnt]=rr1[i2][j2];
				ll[i][j]=cnt;
			}
		}
		if(a[a1[i]]<=mid)i1++;
		else i2++;
	}
}
int main()
{
	scanf("%d%d",&n,&q);
	for(re int i=1;i<=n;i++)scanf("%d",&a[i]),bl[a[i]]=i;
	cnt=n;
	for(re int i=1;i<=q;i++)
	{
		scanf("%d%d",&l[i],&r[i]);
	}
	for(re int i=0;i*B<n;i++)
	{
		re int ta=0;
		for(re int j=1;j<=n;j++)if(a[j]>i*B&&a[j]<=(i+1)*B)a1[++ta]=j;
		for(re int j=1;j<=B;j++)ll1[j]=ll[j];
		dc(i*B+1,std::min(i*B+B,n),a1,ll1);
		for(re int j=1;j<=q;j++)
		{
			re int l1=std::lower_bound(a1+1,a1+ta+1,l[j])-a1;
			re int r1=std::upper_bound(a1+1,a1+ta+1,r[j])-a1-1;
			if(l1<=r1)
			{
				if(ans[j])
				{
					vx[++cnt]=ans[j];vy[cnt]=ll[l1][r1];
					ans[j]=cnt;
				}
				else ans[j]=ll[l1][r1];
			}
		}
	}
	printf("%d\n",cnt);
	for(re int i=n+1;i<=cnt;i++)printf("%d %d\n",vx[i],vy[i]);
	for(re int i=1;i<=q;i++)printf("%d ",ans[i]);
}