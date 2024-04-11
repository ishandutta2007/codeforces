#include <iostream>
#include <string.h>
using namespace std;
int main(){
//int a,b,c;
char str1[100];
char str2[100];
//cin >> a >> b >> c;
cin >> str1 >> str2;
int len1 = strlen(str1); int len2 = strlen(str2);
int i = 0;
for(int j = 0; j < len2; j++){
if (str1[i]==str2[j]) i++;
if(i == len1){ i--;
break;
}
}
cout << i+1 << endl;
return 0;
}