#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
char a[5050], b[5050];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf(" %s %s",a,b);

		int al = strlen(a), bl = strlen(b);

		int fl = 0;
		for(int i=0;i<min(al, bl);i++){
			if(a[i] != b[i]){
				if(a[i] < b[i]) puts(a);
				else if(a[i] > b[i]){
					int fl2 = 0;
					for(int j=al-1;j>i;j--){
						if(a[j] < b[i]){
							fl2 = 1;
							swap(a[i], a[j]);
							break;
						}
					}
					if(fl2) puts(a);
					else{
						int fl3 = 0;
						for(int j=al-1;j>i;j--){
							if(a[j] == b[i]){
								fl3 = 1;
								swap(a[i], a[j]);
								break;
							}
						}
						if(fl3){
							int fl4 = 0;
							for(int i=0;i<min(al, bl);i++){
								if(a[i] < b[i]){
									fl4 = 1;
									break;
								}else if(a[i] > b[i]){
									fl4 = 2;
									break;
								}
							}
							if(fl4 == 1 || (fl4 == 0 && al < bl)) puts(a);
							else puts("---");
						}
						else puts("---");
					}
				}
				fl = 1;
				break;
			}
			else{
				for(int j=i+1;j<al;j++){
					if(a[j] < b[i]){
						swap(a[i], a[j]);
						fl = 1;
						break;
					}
				}
				if(fl){
					puts(a);
					break;
				}
			}
		}

		if(!fl){
			if(al < bl) puts(a);
			else puts("---");
		}
	}
}