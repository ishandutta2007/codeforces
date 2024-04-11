#include<bits/stdc++.h>
using namespace std;
const int B=256;
int n,q,tree[555][266][266],val[22][266][266],pos[4444],a[4444],cnt,cpt,cur;
int arr[22][266],len[22],l,r,res[222222],ll,rr;
int ar[666],br[666],cr[666],la,lb,lc;
pair<int,int> ans[2222222];
char prt[55555555];
void merge(int l,int mid,int r,int node)
{
	la=lb=lc=0;
	for (int i=l;i<=mid;i++) ar[++la]=pos[i];
	for (int i=mid+1;i<=r;i++) br[++lb]=pos[i];
	for (int i=l;i<=r;i++) cr[++lc]=pos[i];
	sort(ar+1,ar+la+1);sort(br+1,br+lb+1);sort(cr+1,cr+lc+1);
	for (int i=1;i<=lc;i++) 
	{
		for (int j=i;j<=lc;j++)
		{
			l=lower_bound(ar+1,ar+la+1,cr[i])-ar;r=lower_bound(ar+1,ar+la+1,cr[j]+1)-ar-1;
			ll=lower_bound(br+1,br+lb+1,cr[i])-br;rr=lower_bound(br+1,br+lb+1,cr[j]+1)-br-1;
			if (l>r) tree[node][i][j]=tree[(node<<1)|1][ll][rr];
			else if (ll>rr) tree[node][i][j]=tree[node<<1][l][r];
			else
			{
				++cnt;
				ans[cnt]=make_pair(tree[node<<1][l][r],tree[(node<<1)|1][ll][rr]);
				tree[node][i][j]=cnt;
			}
		}
	}
}
void solve(int l,int r,int node)
{
	if (l==r) 
	{
		tree[node][1][1]=pos[l];
		return;
	}
	int mid=(l+r)>>1;
	solve(l,mid,node<<1);
	solve(mid+1,r,(node<<1)|1);
	merge(l,mid,r,node);
}
void print(int x)
{
	if (!x)
	{
		prt[cpt++]='0';
		return;
	}
	while(x)
	{
		prt[cpt++]='0'+(x%10);
		x/=10;
	}
}
int main()
{
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) pos[a[i]]=i;
	cnt=n;
	for (int i=0;i*B+1<=n;i++)
	{
		for (int j=i*B+1;j<=min(n,(i+1)*B);j++)
		{
			arr[i][++len[i]]=pos[j];
		}
		sort(arr[i]+1,arr[i]+len[i]+1);
		solve(i*B+1,min(n,(i+1)*B),1);
		for (int j=1;j<=len[i];j++)
		{
			for (int k=j;k<=len[i];k++)
			val[i][j][k]=tree[1][j][k];
		}
	}
	for (int i=1;i<=q;i++)
	{
		scanf("%d%d",&l,&r);cur=-1;
		for (int j=0;j<=(n-1)/B;j++)
		{
			ll=lower_bound(arr[j]+1,arr[j]+len[j]+1,l)-arr[j];
			rr=lower_bound(arr[j]+1,arr[j]+len[j]+1,r+1)-arr[j]-1;
			if (ll>rr) continue;
			if (cur==-1) cur=val[j][ll][rr];
			else 
			{
				++cnt;
				ans[cnt]=make_pair(cur,val[j][ll][rr]);
				cur=cnt;
			}
		}
		res[i]=cur;
	}
	cpt=1;prt[0]='\n';
	for (int i=q;i>=1;i--)
	{
		print(res[i]);
		if (i>1) prt[cpt++]=' ';
	}
	prt[cpt++]='\n';
	for (int i=cnt;i>n;i--)
	{
		print(ans[i].second);
		prt[cpt++]=' ';
		print(ans[i].first);
		prt[cpt++]='\n';
	}
	print(cnt);
	reverse(prt,prt+cpt);
	fwrite(prt,1,cpt,stdout);
	return 0;
}