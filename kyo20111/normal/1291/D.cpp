#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct query{
	int l, r, id;
	bool operator < (const query &a) const{
		return make_pair(l>>9, r) < make_pair(a.l>>9, a.r);
	}
}q[100100];
char s[200200];
int n, cnt, chk[256], ans[100100];
int main(){
	scanf("%s",s+1);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&q[i].l,&q[i].r);
		q[i].id = i;
	}
	sort(q+1, q+1+n);
    int l=1, r=0;

	for(int i=1;i<=n;i++){
    	while(l<q[i].l) if(--chk[s[l++]] == 0) cnt--;
    	while(r<q[i].r) if(chk[s[++r]]++ == 0) cnt++;
    	while(l>q[i].l) if(chk[s[--l]]++ == 0) cnt++;
    	while(r>q[i].r) if(--chk[s[r--]] == 0) cnt--;

    	//printf("%d %d %d\n",l,r,cnt);
		ans[q[i].id] = (cnt == 1 && q[i].r-q[i].l > 0);
		if(cnt == 2 && s[l] == s[r]) ans[q[i].id] = 1;
	}
	for(int i=1;i<=n;i++) puts(ans[i] ? "No" : "Yes");
}