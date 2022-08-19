#include<iostream>
#include<cstdio>
using namespace std;
typedef long long LL;
LL k, x, m, n;
LL nums1[55];
LL nums2[55];
LL nums1s2[55];
LL nums2s1[55];
LL nums2s2[55];
LL start[55];
LL end[55];
LL numocc(LL firstm, LL lastm, LL ACm, LL firstn, LL lastn, LL ACn){
	LL ans = ACn*nums1[k]+ACm*nums2[k];
	if((lastn == 1) && (firstm == 2)){
		ans += nums1s2[k];
	}
	if((lastm == 1) && (firstn == 2)){
		ans += nums2s1[k];
	}
	if((lastm == 1) && (firstm == 2)){
		ans += nums2s2[k];
	}
	return ans;
}
void print(LL n1, LL firstn, LL lastn, LL ACn){
	if(n1 == 1){
		if(firstn == 1){
			printf("A\n");
		} else if(firstn == 2){
			printf("C\n");
		} else {
			printf("B\n");
		}
		return;
	} else if(n1 == 2){
		if(firstn == 1){
			printf("A");
		} else if(firstn == 2){
			printf("C");
		} else {
			printf("B");
		}
		if(lastn == 1){
			printf("A\n");
		} else if(lastn == 2){
			printf("C\n");
		} else {
			printf("B\n");
		}

		return;
	}
	if(ACn*2 == n1){
		for(int i = 0; i < ACn; i++){
			printf("AC");
		}
		printf("\n");
		return;
	}
	if(ACn*2 == n1-1){
		if(firstn == 1){
			for(int i = 0; i < ACn; i++){
			printf("AC");
			}
			if(lastn == 1){
			printf("A\n");
			} else if(lastn == 2){
			printf("C\n");
			} else {
			printf("B\n");
			}
			return;
		} else if(lastn == 2){
			if(firstn == 1){
			printf("A");
			} else if(firstn == 2){
			printf("C");
			} else {
			printf("B");
			}
			for(int i = 0; i < ACn; i++){
			printf("AC");
			}
		printf("\n");
		}
		return;
	}
	if(firstn == 1){
			printf("A");
	} else if(firstn == 2){
			printf("C");
	} else {
			printf("B");
	}
	for(int i = 0; i < ACn; i++){
			printf("AC");
	}
	for(int i = 0; i < n1-2-ACn*2; i++){
			printf("B");
	}
	if(lastn == 1){
			printf("A\n");
	} else if(lastn == 2){
			printf("C\n");
	} else {
			printf("B\n");
	}
	return;
}
int main(){
	scanf("%d%d%d%d", &k, &x, &n, &m);
	nums1  [3] = 1;
	nums2  [3] = 1;
	nums1s2[3] = 1;
	nums2s1[3] = 0;
	nums2s2[3] = 0;
	start  [3] = 1;
	end    [3] = 2;
	nums1  [4] = 1;
	nums2  [4] = 2;
	nums1s2[4] = 1;
	nums2s1[4] = 1;
	nums2s2[4] = 0;
	start  [4] = 2;
	end    [4] = 2;
	for(LL i = 5; i <= 50; i++){
		nums1[i] = nums1[i-1]+nums1[i-2];
		nums2[i] = nums2[i-1]+nums2[i-2];
		nums1s2[i] = nums1s2[i-1]+nums1s2[i-2];
		nums2s1[i] = nums2s1[i-1]+nums2s1[i-2] + ((end[i-2] == 2) && (start[i-1]==1));
		nums2s2[i] = nums2s2[i-1]+nums2s2[i-2] + ((end[i-2] == 2) && (start[i-1]==2));
		start[i] = start[i-2];
		end[i] = end[i-1];
	}
	//cout << nums1[6] << " " << nums2[6] << " " << nums1s2[6] << " " << nums2s1[6] << " " << nums2s2[6] << endl;
	//cout << numocc(2,2,0,2,1,0) << endl;
	for(LL firstn = 1; firstn <= 2+(n <= 3); firstn++){
	for(LL  lastn = 1;  lastn <= 2+(n <= 3);  lastn++){
	for(LL firstm = 1; firstm <= 2+(m <= 3); firstm++){
	for(LL  lastm = 1;  lastm <= 2+(m <= 3);  lastm++){
		for(LL ACn = 0; ACn*2 <= n; ACn++){
		for(LL ACm = 0; ACm*2 <= m; ACm++){
			if((n == 1) && firstn != lastn) continue;
			if((m == 1) && firstm != lastm) continue;
			if((n == 2) && ACn != ((firstn == 1) && (lastn == 2))) continue;
			if((m == 2) && ACm != ((firstm == 1) && (lastm == 2))) continue;
			if((n >  2) && (ACn*2 > (n-2+ (firstn == 1) + (lastn == 2)))) continue;
			if((m >  2) && (ACm*2 > (m-2+ (firstm == 1) + (lastm == 2)))) continue;
			if(numocc(firstm, lastm, ACm, firstn, lastn, ACn) == x){
				print(n, firstn, lastn, ACn);
				print(m, firstm, lastm, ACm);
				return 0;
			}
		}
		}
	}
	}
	}
	}
	printf("Happy new year!\n");
	return 0;
}