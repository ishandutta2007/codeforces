#include<cstdio>
#include<algorithm>
#include<set>
#define MAXN 200000
using namespace std;
void Read(int &x){
	char c;
	while(c=getchar(),c!=EOF)
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return;
		}
}
int n,s,ans,cnt[MAXN+10],a[MAXN+10];
multiset<int,greater<int> >st;
void read(){
	Read(n),Read(s);
	int i;
	for(i=1;i<=n;i++)
		Read(a[i]);
}
void solve(){
	int i,j;
	for(i=1;i<=n;i++){
		if(i==s){
			if(a[i])
				ans++;
		}
		else{
			cnt[a[i]]++;
			if(!a[i])
				ans++;
			else
				st.insert(a[i]);
		}
	}
	for(j=n;!cnt[j];j--);
	for(i=1;i<=n&&i<j;i++){
		if(!cnt[i]){
			if(cnt[0]){
				cnt[0]--;
				cnt[i]++;
				st.insert(i);
				goto it;
			}
			int t=*st.begin();
			ans++;
			st.erase(st.begin());
			cnt[t]--;
			cnt[i]++;
			st.insert(i);
		}
		it:while(!cnt[j])
			j--;
	}
	printf("%d\n",ans);
}
int main()
{
	read();
	solve();
}