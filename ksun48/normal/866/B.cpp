#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	LL n, S;
	cin >> n >> S;
	LL s[n], a[n], b[n];
	LL ans = 0;
	LL ns = 0;
	LL nsa = 0;
	LL nsb = 0;
	map<LL,LL> abetter, bbetter;
	for(int i = 0; i < n; i++){
		cin >> s[i] >> a[i] >> b[i];
		LL v = min(a[i], b[i]);
		ans += max(a[i],b[i])*s[i];
		a[i] -= v;
		b[i] -= v;
		ns += s[i];
		if(a[i] > 0){
			nsa += s[i];
			abetter[a[i]] += s[i];
		} else {
			nsb += s[i];
			bbetter[b[i]] += s[i];
		}
	}

	LL np = ns / S;
	while(np*S < ns) np++;
	LL npa = nsa / S;
	while(npa*S < nsa) npa++;
	LL npb = nsb / S;
	while(npb*S < nsb) npb++;

	if(npa + npb == np){
		cout << ans << endl;
		return 0;
	}
	LL la = nsa - (npa-1)*S;
	LL lb = nsb - (npb-1)*S;
	LL ta = 0;
	LL tb = 0;
	for(LL c = 0; c < 200000; c++){
		while(la > 0 && abetter[c]){
			la--;
			abetter[c]--;
			ta += c;
		}
		while(lb > 0 && bbetter[c]){
			lb--;
			bbetter[c]--;
			tb += c;
		}
	}
	cout << ans - min(ta,tb) << endl;
}