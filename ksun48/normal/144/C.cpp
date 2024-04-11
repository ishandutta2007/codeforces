#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
int DEBUG = 0;
main(int argc, char **argv) {
  char str1[500001];
  char str2[500001];
  scanf("%s%s", str1, str2);
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  if(len1<len2){
    printf("0\n"); exit(0);
  }
  int freq1[26], freq2[26];
  int numwork = 0;
  for(int i = 0; i < 26; i++){
    freq2[i] = 0;
  }
  for(int i = 0; i < len1; i++){
    freq2[str2[i]-'a']++;
  }  
  for(int j = 0; j < 26; j++){
    if(DEBUG) printf("%d ", freq2[j]);
  }
  if(DEBUG) printf("\n");
  for(int j = 0; j < 26; j++){
    freq1[j] = 0;
  }
  for(int i = 0; i < len2; i++){
    if(str1[i] != '?'){
      freq1[str1[i]-'a']++;
    }
  }   
  for(int j = 0; j < 26; j++){
    if(DEBUG) printf("%d ", freq1[j]);
  }
  if(DEBUG) printf("\n");
  int iswork = 1;
  for(int j = 0; j < 26; j++){
    if(freq1[j] > freq2[j]){
      iswork = 0;
      break;
    }
  }  
  if(iswork){
    numwork++;
    if(DEBUG) printf("%d\n", 0);
  }
  for(int i = 1; i <= len1-len2; i++){
    if(str1[i-1] != '?'){
      freq1[str1[i-1]-'a']--;
    }
    if(str1[i+len2-1] != '?'){
      freq1[str1[i+len2-1]-'a']++;
    }
    for(int j = 0; j < 26; j++){
      if(DEBUG) printf("%d ", freq1[j]);
    }
    if(DEBUG) printf("\n");
    iswork = 1;
    for(int j = 0; j < 26; j++){
      if(freq1[j] > freq2[j]){
	iswork = 0;
	break;
      }
    }
    if(iswork){
      numwork++;
      if(DEBUG) printf("%d\n", i);
    }
  }
  printf("%d\n", numwork);
  exit(0);
}