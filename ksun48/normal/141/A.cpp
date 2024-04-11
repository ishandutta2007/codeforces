#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
main(int argc, char **argv) {
  char str1[100], str2[100], str3[100];
  scanf("%s%s%s", str1, str2, str3);
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  int len3 = strlen(str3);
  int freqsum[26];
  for(int i = 0; i < 26; i++){
    freqsum[i] = 0;
  }
  for(int i = 0; i < len1; i++){
    freqsum[str1[i]-'A']++;
  }
  for(int i = 0; i < len2; i++){
    freqsum[str2[i]-'A']++;
  }
  for(int i = 0; i < len3; i++){
    freqsum[str3[i]-'A']--;
  }
  for(int i = 0; i < 26; i++){
    if(freqsum[i] != 0){
      printf("NO\n");
      exit(0);
    }
  }
  printf("YES\n");
  exit(0);
}