#include <iostream>
#include <string>
#include <vector>

using namespace std;

int T, k;
string s, a, b;
int p[26], revp[26];
int q[26], revq[26];
vector<int> vec;

bool checkL(int i)
{
	for(int j = 0; j < 26; j++) q[j] = p[j], revq[j] = revp[j];
	int u = s[i] - 'a', l = a[i] - 'a', r = b[i] - 'a';
	
	if(q[u] != -1 && q[u] != l) return false;
	if(q[u] == -1){
		if(revq[l] != -1) return false;
		q[u] = l;
		revq[l] = u;
	}
	
	for(i++; i < s.size(); i++){
		int u = s[i] - 'a', l = a[i] - 'a';
		//for(int i = 0; i < k; i++) cout << p[i] << " "; cout << "\n";
		if(q[u] != -1){
			int v = q[u];
			if(v < l) return false;
			if(v > l) goto ok;
		}
		else{
			for(int j = l+1; j < k; j++){
				if(revq[j] == -1){
					q[u] = j;
					revq[j] = u;
					goto ok;
				}
			}
			if(revq[l] != -1) return false;
			q[u] = l;
			revq[l] = u;
		}
	}
	
	ok:;
	for(int j = 0; j < 26; j++) p[j] = q[j], revp[j] = revq[j];
	return true;
}

bool checkR(int i)
{
	for(int j = 0; j < 26; j++) q[j] = p[j], revq[j] = revp[j];
	int u = s[i] - 'a', l = a[i] - 'a', r = b[i] - 'a';
	
	if(q[u] != -1 && q[u] != r) return false;
	if(q[u] == -1){
		if(revq[r] != -1) return false;
		q[u] = r;
		revq[r] = u;
	}
	
	for(i++; i < s.size(); i++){
		int u = s[i] - 'a', l = a[i] - 'a', r = b[i] - 'a';
		if(q[u] != -1){
			int v = q[u];
			if(v > r) return false;
			if(v < r) goto ok;
		}
		else{
			for(int j = 0; j < r; j++){
				if(revq[j] == -1){
					q[u] = j;
					revq[j] = u;
					goto ok;
				}
			}
			if(revq[r] != -1) return false;
			q[u] = r;
			revq[r] = u;
		}
	}
	
	ok:;
	for(int j = 0; j < 26; j++) p[j] = q[j], revp[j] = revq[j];
	return true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> k;
		cin >> s >> a >> b;
		for(int i = 0; i < 26; i++) p[i] = revp[i] = -1;
		
		for(int i = 0; i < s.size(); i++){
			int u = s[i] - 'a', l = a[i] - 'a', r = b[i] - 'a';
			
			if(p[u] != -1){
				int v = p[u];
				if(v < l || v > r) goto ng;
				if(v > l && v < r) goto ok;
				if(l < r){
					if(v == l){
						if(checkL(i)) goto ok;
						else goto ng;
					}
					if(v == r){
						if(checkR(i)) goto ok;
						else goto ng;
					}
				}
			}
			else{
				if(l == r){
					if(revp[l] != -1) goto ng;
					p[u] = l;
					revp[l] = u;
				}
				else if(l+2 <= r){
					for(int j = l+1; j < r; j++){
						if(revp[j] == -1){
							p[u] = j;
							revp[j] = u;
							goto ok;
						}
					}
					if(checkL(i)) goto ok;
					if(checkR(i)) goto ok;
					goto ng;
				}
				else{
					if(checkL(i)) goto ok;
					if(checkR(i)) goto ok;
					goto ng;
				}
			}
			
			//for(int i = 0; i < k; i++) cout << p[i] << " "; cout << "\n";
		}
		
		ok:;
		cout << "YES" << "\n";
		//for(int i = 0; i < k; i++) cout << p[i] << " "; cout << "\n";
		//for(int i = 0; i < k; i++) cout << revp[i] << " "; cout << "\n";
		vec.clear();
		for(int i = 0; i < k; i++) if(revp[i] == -1) vec.push_back(i);
		for(int i = 0; i < k; i++) if(p[i] == -1) p[i] = vec.back(), vec.pop_back();
		for(int i = 0; i < k; i++) cout << (char)(p[i]+'a'); cout << "\n";
		continue;
		
		ng:;
		cout << "NO" << "\n";
	}
	fflush(stdout);
	
	return 0;
}