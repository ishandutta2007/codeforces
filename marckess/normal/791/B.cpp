#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int, int>

using namespace std;

vi p(150005);
vector<ll> ari(150005,0);
vector<ll> ver(150005,1);
vb isP(150005,true);

int parent(int a){
	if (p[a] != a)
		p[a] = parent(p[a]);
	return p[a];
}

void connect(int a, int b){
	int pa = parent(a);
	int pb = parent(b);

	if(pa != pb){
		if ( pa > pb )
			swap(pa,pb);

		p[pb] = pa;
		isP[pb] = false;
		ari[pa] += ari[pb] + 1;
		ver[pa] += ver[pb];
	}else{
		ari[pa]++; 
	}

}

int main(){
	int n, k, a, b;
	cin >> n >> k;

	for(int i = 1; i <= n; i++ )
		p[i]=i;

	while(k--){
		cin >> a >> b;
		connect(a,b);
	}

	bool res = true;
	for(int i = 1; i <= n; i++ ){
		if ( isP[i] ){
			ll vr = ver[i];
			if ( vr*(vr-1)/2 != ari[i] )
				res = false;
		}
	}

	if(res)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}