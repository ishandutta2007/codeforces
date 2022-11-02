#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int mv[1010];

int ac[1010];
int re[1010];

int n;

void ask(){
	vector<int> q;
	for (int i=1;i<=n;i++){
		if (ac[i]){
			q.push_back(i);
		}
	}
	if (q.size()==0) return;
	cout<<(int)q.size()<<endl;
	for (int i=0;i<(int)q.size();i++){
		cout<<q[i];
		if (i+1<(int)q.size()){
			cout<<" ";
		}
	}
	cout<<endl;
	for (int i=1;i<=n;i++){
		cin>>re[i];
	}
	for (int i=1;i<=n;i++){
		if (ac[i]==0){
			mv[i]=min(mv[i], re[i]);
		}
	}
}

int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		mv[i]=1e9+10;
	}
	for (int st=1024;st>=2;st/=2){
		for (int i=0;i<n;i++){
			if (i%st>=st/2){
				ac[i+1]=1;
			}
			else{
				ac[i+1]=0;
			}
		}
		ask();
		for (int i=0;i<n;i++){
			if (i%st>=st/2){
				ac[i+1]=0;
			}
			else{
				ac[i+1]=1;
			}
		}
		ask();
	}
	cout<<-1<<endl;
	for (int i=1;i<=n;i++){
		cout<<mv[i];
		if (i<n) cout<<" ";
	}
	cout<<endl;
}