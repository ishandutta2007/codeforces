#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

ll t[202020];
int k[202020];

ll a,b,c;

int test(int n, int x){
	int ah=x;
	int bh=x;
	int ch=x;
	for (int i=n-1;i>=0;i--){
		if (t[i]<=c&&ch>0&&k[i]==0){
			ch--;
			k[i]=2;
		}
		else if (t[i]<=a&&ah>0&&k[i]==0){
			ah--;
			k[i]=2;
		}
		else if (t[i]<=b&&bh>0&&k[i]==0){
			bh--;
			k[i]=2;
		}
		else if(t[i]<=a+b&&ah>0&&bh>0&&k[i]==0){
			ah--;
			bh--;
			k[i]=2;
		}
		//cout<<ah<<" "<<bh<<" "<<ch<<endl;
	}
	
	int f=0;
	for (int i=0;i<n;i++){
		if (k[i]==0) f=1;
		if (k[i]==2) k[i]=0;
	}
	if (!f) return 1;
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n>>a>>b>>c;
	if (a>b) swap(a, b);
	if (b>c) swap(b, c);
	if (a>b) swap(a, b);
	if (b>c) swap(b, c);
	if (a>b) swap(a, b);
	if (b>c) swap(b, c);
	for (int i=0;i<n;i++){
		cin>>t[i];
		if (t[i]>a+b+c){
			cout<<-1<<endl;
			return 0;
		}
	}
	sort(t, t+n);
	int v=0;
	for (int i=n-1;i>=0;i--){
		if (t[i]>b+c){
			n--;
			v++;
		}
	}
	if (n==0){
		cout<<v<<endl;
		return 0;
	}
	int at=0;
	int bt=0;
	int ct=0;
	for (int i=n-1;i>=0;i--){
		if (t[i]>c){
			if (a+b>=t[i]){
				n--;
				ct++;
				v++;
			}
			else if(a+c>=t[i]){
				n--;
				bt++;
				v++;
			}
			else if(b+c>=t[i]){
				n--;
				at++;
				v++;
			}
		}
	}
	if (n==0){
		cout<<v<<endl;
		return 0;
	}
	for (int i=n-1;i>=0;i--){
		if (at>0&&t[i]<=a){
			k[i]=1;
			at--;
		}
		else if (bt>0&&t[i]<=b){
			k[i]=1;
			bt--;
		}
		else if (ct>0&&t[i]<=c){
			k[i]=1;
			ct--;
		}
	}
	int vv=v+n;
	int mi=0;
	int ma=n;
	while (mi<=ma){
		int mid=(mi+ma)/2;
		if (test(n, mid)){
			ma=mid-1;
			vv=min(vv, v+mid);
		}
		else{
			mi=mid+1;
		}
	}
	cout<<vv<<endl;
}