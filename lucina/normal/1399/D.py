#python review 
#code and debug at atcoder.jp custom test
t = int(input())
for test_case in range(t):
  end_one = []
  end_zero = []
  col = []
  ptr = 0
  n = int(input())
  s = input()
  for i in range(n):
    if (s[i] == '1') :
      if (len(end_zero) == 0):
        ptr += 1
        end_one.append(ptr)           
        col.append(ptr)
      else : 
        c = end_zero.pop(len(end_zero) - 1)
        end_one.append(c)        
        col.append(c)
    else :
      if (len(end_one) == 0) :
        ptr += 1           
        end_zero.append(ptr)
        col.append(ptr)
      else : 
        c = end_one.pop(len(end_one) - 1)
        end_zero.append(c)
        col.append(c)
  print(ptr)
  for i in col:
      print(i, end = ' ')
  print()