#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

const int K=5;

int slv[222][K];

int n;

int pts(int i, vector<int> base){
	int p=0;
	for (int j=0;j<K;j++){
		if (slv[i][j]!=-1){
			int val=base[j]-(base[j]/250)*slv[i][j];
			p+=val;
		}
	}
	return p;
}

int win(int na, int p){
	int tot=n+na;
	vector<int> s(K);
	for (int j=0;j<K;j++){
		if (p&(1<<j)){
			s[j]+=na;
		}
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<K;j++){
			if (slv[i][j]!=-1){
				s[j]++;
			}
		}
	}
	vector<int> base(K);
	for (int i=0;i<K;i++){
		if (s[i]*2>tot) base[i]=500;
		else if (s[i]*4>tot) base[i]=1000;
		else if (s[i]*8>tot) base[i]=1500;
		else if (s[i]*16>tot) base[i]=2000;
		else if (s[i]*32>tot) base[i]=2500;
		else base[i]=3000;
	}
	if (pts(0, base)>pts(1, base)){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for (int i=0;i<n;i++){
		for (int j=0;j<K;j++){
			cin>>slv[i][j];
		}
	}
	for (int i=0;i<64*n;i++){
		for (int p=0;p<(1<<K);p++){
			int ok=1;
			for (int j=0;j<K;j++){
				if ((1<<j)&p){
					if (slv[0][j]==-1){
						ok=0;
						break;
					}
				}
			}
			if (ok){
				if (win(i, p)){
					cout<<i<<endl;
					return 0;
				}
			}
		}
	}
	cout<<-1<<endl;
}