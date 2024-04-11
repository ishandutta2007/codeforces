#include <stdio.h>
#include <string.h>

int N,cnt[26],num[1004],maxcnt,maxc,ocnt;
char A[1004],B[1004],maxchar;

int main()
{
    int i,j,k;
    scanf("%s",A+1);
    N = strlen(A+1);
    for (i=1;i<=N;i++) cnt[A[i]-'a']++, num[i] = 1e9;
    for (i=0;i<26;i++) if (maxcnt < cnt[i]) maxcnt = cnt[i], maxchar = i+'a';
    for (i=2;i<=N;i++){
        for (j=2;j<i;j++) if (i%j == 0) break;
        if (j < i) continue;
        // if prime
        k = i;
        for (j=i;j<=N;j+=i) if (k > num[j]) k = num[j];
        for (j=i;j<=N;j+=i) num[j] = k;
    }
    for (i=1;i<=N;i++) if (num[i] == 2) maxc++; else ocnt++;
    if (maxcnt < maxc){ puts("NO"); return 0; }
    puts("YES");
    for (i=1;i<=N;i++) if (num[i] == 2) B[i] = maxchar;
    cnt[maxchar-'a'] -= maxc;
    for (i=1;i<=N;i++) if (num[i] != 2){
        for (j=0;j<26;j++) if (cnt[j]) break;
        cnt[j]--;
        B[i] = j+'a';
    }
    puts(B+1);
}