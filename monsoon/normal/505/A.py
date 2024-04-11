def main():
  s = raw_input()
  for i in range(len(s)+1):
    for c in range(ord('a'), ord('z')+1):
      sc = s[:i] + chr(c) + s[i:]
      if sc == sc[::-1]:
        print sc
        return
  print "NA"

main()