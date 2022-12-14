#include <cstdio>
const int MAXN = 200005;

char str1[MAXN], str2[MAXN];
int cnt1[60], cnt2[60];

inline int getID(char x){
	if(x >= 'a' && x <= 'z') return x - 'a' + 1;
	return x - 'A' + 27;
}
inline int min(int a, int b){return a > b ? b : a;}
int main(){
	int i, yay = 0, whoop = 0;
	scanf("%s%s", str1, str2);
	for(i = 0; str1[i]; ++ i)
		cnt1[getID(str1[i])] ++;
	for(i = 0; str2[i]; ++ i)
		cnt2[getID(str2[i])] ++;
	for(i = 1; i <= 52; ++ i){
		int dt = min(cnt1[i], cnt2[i]);
		yay += dt;
		cnt1[i] -= dt;
		cnt2[i] -= dt;
	}
	for(i = 1; i <= 26; ++ i){
		int dt = min(cnt1[i], cnt2[i + 26]);
		whoop += dt;
		cnt1[i] -= dt;
		cnt2[i + 26] -= dt;
	}
	for(i = 27; i <= 52; ++ i){
		int dt = min(cnt1[i], cnt2[i - 26]);
		whoop += dt;
		cnt1[i] -= dt;
		cnt2[i - 26] -= dt;
	}
	printf("%d %d\n", yay, whoop);
	return 0;
}