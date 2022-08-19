#include <cstdio>
using namespace std;
inline bool HW(int a,int b) {
	return (a%10==b/10 && a/10==b%10);
}
int h,m,time;
int main() {
	scanf("%d:%d",&h,&m);
	for (time=h*60+m+1;time<=24*60;time++) {
		if (time==24*60 || HW(time/60,time%60)) {
			printf("%02d:%02d",time/60%24,time%60);
			break;
		}
	}
}