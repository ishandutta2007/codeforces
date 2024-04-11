#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

int N;
int A[MAXN], pos[MAXN];
int L[MAXN], R[MAXN];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i=1;i<=N;i++) cin >> A[i], pos[A[i]] = i;
	stack <int> stk;
	for (int i=1;i<=N;i++){
		while (!stk.empty() && A[stk.top()] < A[i]) stk.pop();
		L[i] = stk.empty() ? 1 : stk.top()+1;
		stk.push(i);
	}
	stk = {};
	for (int i=N;i;i--){
		while (!stk.empty() && A[stk.top()] < A[i]) stk.pop();
		R[i] = stk.empty() ? N : stk.top()-1;
		stk.push(i);
	}
	int ans = 0;
	for (int i=1;i<=N;i++){
		if (i-L[i] <= R[i]-i){
			for (int j=L[i];j<i;j++){
				int x = A[i]-A[j];
				if (i < pos[x] && pos[x] <= R[i]) ans++;
			}
		}else{
			for (int j=R[i];j>i;j--){
				int x = A[i]-A[j];
				if (i > pos[x] && pos[x] >= L[i]) ans++;
			}
		}
	}
	cout << ans << endl;
}