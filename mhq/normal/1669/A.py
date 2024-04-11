tst = int(input())
for it in range(tst):
  x= int(input())
  if x >= 1900:
    print("Division 1")
  elif x >= 1600:
    print("Division 2")
  elif x >= 1400:
    print("Division 3")
  else:
    print("Division 4")