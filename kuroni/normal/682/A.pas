var n, m, ans: int64;
    i: longint;
    A: array[0..4] of int64;

begin
  read(n,m);
  A[0] := (m div 5) * (n div 5);
  for i := 1 to 4 do A[i] := (n div 5 + ord(i <= (n mod 5))) * (m div 5 + ord((5 - i) <= (m mod 5)));
  for i := 0 to 4 do inc(ans, A[i]);
  write(ans);
end.