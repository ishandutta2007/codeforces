#include <cstdio>
#include <cstring>

char a[200005], b[200005];

bool comp(int l1, int r1, int l2, int r2){
	for(int i = l1, j = l2; i <= r1 && j <= r2; ++ i, ++ j)
		if(a[i] != b[j]) return false;
	return true;
}
bool isEqu(int l1, int r1, int l2, int r2){
	if((r1 - l1 + 1) & 1) return comp(l1, r1, l2, r2);
	int mid1 = (l1 + r1) >> 1, mid2 = (l2 + r2) >> 1;
	return (isEqu(l1, mid1, l2, mid2) && isEqu(mid1 + 1, r1, mid2 + 1, r2)) || (isEqu(l1, mid1, mid2 + 1, r2) && isEqu(mid1 + 1, r1, l2, mid2));
}
int main(){
	int len;
	scanf("%s%s", a + 1, b + 1);
	len = strlen(a + 1);
	printf("%s\n", isEqu(1, len, 1, len) ? "YES" : "NO");
}