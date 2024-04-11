#include<cstdio>
const int N=200002;
int Ans;
int T,n,a[N],s[N],l,r,i,cnt;
int main(){
	scanf("%d",&T);
	while(T--){
		cnt=0;
		Ans=-1;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			s[i]=0,scanf("%d",a+i);
		for(l=r=1;r<=n;r++){
			s[a[r]]++;
			if(s[a[r]]==2)
				cnt++;
			while(cnt>=2||(cnt==1&&s[a[l]]==1)||(cnt==1&&s[a[r]]==3)){
				if(s[a[l]]==2)
					cnt--;
				s[a[l]]--;
				l++;
			}
			if(cnt==1&&(Ans==-1||r-l+1<Ans))
				Ans=r-l+1;
		}
		printf("%d\n",Ans);
	}
	//while(1);
}