#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MaxN = 105;

int ok[MaxN][MaxN];
int N, C;
vector<int> vleft[MaxN], vright[MaxN];

void input(){
	cin >> N >> C;
	for(int i = 0; i < C; i++){
		int u, v;
		string str;
		cin >> u >> v >> str;

		if(str == "LEFT")
			vleft[u].push_back(v);
		else
			vright[u].push_back(v);
	}
}

void print_res(int L, int R){
//	cout << "print_res " << L << " " << R << endl;
	if(L > R) return;
	if(L == R){
		cout << L << " ";
		return;
	}

	print_res(L+1, ok[L][R]);
	cout << L << " ";
	print_res(ok[L][R]+1, R);

//	for(int i = L; i <= R; i++){
//		if(ok[L+1][i] && ok[i+1][R]){
//			print_res(L+1, i);
//			cout << L << " ";
//			print_res(i+1, R);
//			return; 
//		}
//	}
}

int main(){
	input();


	for(int d = -1; d < N; d++){
		for(int L = max(-d+1, 1); L+d <= N; L++){
			int R = L+d;
			if(d == -1 || (d == 0 && vleft[L].empty() && vright[L].empty())){
				ok[L][R] = 1010101010;
				continue;
			}

			int minL = N, maxL = 1, minR = N, maxR = 1;
			for(int v: vleft[L]){
				minL = min(minL, v);
				maxL = max(maxL, v);
			}
			for(int v: vright[L]){
				minR = min(minR, v);
				maxR = max(maxR, v);
			}

//			if(minL > maxL && minR > maxR){
//				for(int i = L+1; i < R; i++)
//			}


//			cout << L << " " << R << " " << minL << " " << maxL << " "
//				<< minR << " " << maxR << endl;

			bool cok = true;
			if(minL <= maxL && (minL < L || maxL > R)) cok = false;
//			cout << cok << endl;
			if(minR <= maxR && (minR < L || maxR > R)) cok = false;
//			cout << cok << endl;
			if(minL <= maxL && minR <= maxR && maxL >= minR) cok = false;
//			cout << cok << endl;
			// L <= minL <= maxL < minR <= maxR <= R
			if(!cok){
				ok[L][R] = 0;
			} else {
				if(minL > maxL){
					minL = maxL = L-1;
				}
				if(minR > maxR) minR = maxR = R+1;
//				cout << maxL << " " << minR << endl;

				for(int i = max(L,maxL); i <= min(R,minR); i++)
					if(ok[L+1][i] && ok[i+1][R]){
//						cout << " " << L << " " << R << " " << i << endl;
						ok[L][R] = i;
						break;
					}
			}

		}
	}

	if(!ok[1][N]){
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}

	print_res(1, N);
	cout << endl;
}