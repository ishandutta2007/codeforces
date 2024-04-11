#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

void nie(){
	cout<<"NO"<<endl;
	exit(0);
}

vector<pair<int, char> > ans;

void rm(vector<ll>&t, int i){
	for (int j=i;j+1<(int)t.size();j++){
		t[j]=t[j+1];
	}
	t.pop_back();
}

void go(int ak, vector<ll> t){
	while((int)t.size()>1){
		ll ma=0;
		for (int i=0;i<(int)t.size();i++){
			ma=max(ma, t[i]);
		}
		int f=0;
		for (int i=0;i<(int)t.size();i++){
			if (t[i]==ma){
				if (i>0&&t[i]>t[i-1]){
					ans.push_back({ak+i, 'L'});
					t[i]+=t[i-1];
					rm(t, i-1);
					f=1;
					break;
				}
				if (i+1<(int)t.size()&&t[i]>t[i+1]){
					ans.push_back({ak+i, 'R'});
					t[i]+=t[i+1];
					rm(t, i+1);
					f=1;
					break;
				}
			}
		}
		if (!f) nie();
	}
}

ll a[555];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	int k;
	cin>>k;
	int i2=1;
	for (int i=0;i<k;i++){
		vector<ll> t;
		ll b;
		cin>>b;
		ll su=0;
		while (su<b&&i2<=n){
			t.push_back(a[i2]);
			su+=a[i2++];
		}
		if (su!=b) nie();
		go(i+1, t);
	}
	if (i2!=n+1) nie();
	cout<<"YES"<<endl;
	for (auto aa:ans){
		cout<<aa.F<<" "<<aa.S<<"\n";
	}
}