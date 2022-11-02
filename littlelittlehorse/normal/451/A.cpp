#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;

int main(){
    scanf("%d%d", &n, &m);
    if (min(n, m) & 1) printf("Akshat\n");
    else printf("Malvika\n");
}