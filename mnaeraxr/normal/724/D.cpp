#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

char s[maxn];
char ans[maxn];
int pnt = 0;

bool ok[maxn];
int ds[maxn];

int root(int a){
	return ds[a] < 0 ? a : ds[a] = root(ds[a]);
}

void join(int a, int b){
	ds[a] = b;
}

int next(int a){
	a = max(a, -1);
	return root(a + 1);
}

int main(){

	int n;
	scanf("%d", &n);
	scanf("%s", s);

	int l = strlen(s);

	vector<vi> pos(26);

	for (int i = 0; i < l; ++i){
		pos[s[i] - 'a'].push_back(i);
		ds[i] = -1;
	}

	ds[l] = ds[l + 1] = -1;

	int canc = 0;

	l -= n - 1;

	for (int i = 0; i < 26; ++i){

		int total = 0;

//		cout << endl << i << " ";
//		cout << canc << endl;

		for (int j = 0; j < (int)pos[i].size(); ++j){
			int it = next(pos[i][j] - n);

			if (pos[i][j] < it || it >= l) continue;

			if (j + 1 < (int)pos[i].size()){
				int jt = next(pos[i][j + 1] - n);

				if (jt == it)
					continue;
			}

			total++;

			while (it <= min(pos[i][j], l - 1)){
				ok[it] = true;
				canc++;
				join(it, it + 1);
				it = next(it);
			}
		}

		if (canc == l){
			for (int j = 0; j < total; ++j)
				ans[pnt++] = (char)(i + 'a');
		}
		else{
			for (int j = 0; j < (int)pos[i].size(); ++j)
				ans[pnt++] = (char)(i + 'a');
		}
	}

	for (int i = 0; i < pnt; ++i)
		putchar(ans[i]);

	putchar('\n');




	return 0;
}