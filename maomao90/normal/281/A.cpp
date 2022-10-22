#include <bits/stdc++.h>
using namespace std;

char str[1005];

int main() {
scanf("%s", str);
if (str[0] >= 'a') str[0] -= 32;
printf("%s\n", str);
return 0;
}