#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 110;
char s[N];
int n, vis[N];
vector<char> A, B; 
char inline pre(char c){
	return 'a' + ((c - 'a' + 25) % 26);
}
char inline nxt(char c){
	if(c == 'z') return '?';
	return 'a' + ((c - 'a' + 1) % 26);
}
int main(){
	
	int T; scanf("%d", &T);
	while(T--){
		A.clear(); B.clear();
		scanf("%s", s + 1);
		n = strlen(s + 1);
		for(int i = 1; i <= n; i++){
			if((s[i] - 'a') & 1) A.push_back(s[i]);
			else B.push_back(s[i]);
		}
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		if(A.empty() || B.empty()){
			for(int i = 0; i < A.size(); i++)
				putchar(A[i]);
			for(int i = 0; i < B.size(); i++)
				putchar(B[i]);
			printf("\n");
		}else if(pre(A.back()) != B[0] && nxt(A.back()) != B[0]){
			for(int i = 0; i < A.size(); i++)
				putchar(A[i]);
			for(int i = 0; i < B.size(); i++)
				putchar(B[i]);
			printf("\n");
		}else if(pre(B.back()) != A[0] && nxt(B.back()) != A[0]){
			for(int i = 0; i < B.size(); i++)
				putchar(B[i]);
			for(int i = 0; i < A.size(); i++)
				putchar(A[i]);
			printf("\n");
		}else puts("No answer");
	}
	return 0;
}