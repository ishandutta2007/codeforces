#include <stdio.h>

char str[55];
int n,t;

int main(){
  scanf("%d%d%s", &n, &t, str);
  for(int i = 0; i < t; i++){
    int ptr = 0;
    while(ptr < n-1){
      if(str[ptr] == 'B' && str[ptr+1] == 'G'){
        str[ptr] = 'G'; str[ptr+1] = 'B'; ptr += 2;
      } else ptr++;
    }
  }
  printf("%s\n", str);
}