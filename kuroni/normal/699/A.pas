uses math;
var i: longint;
    n, ans: int64;
    A: array[1..200000] of longint;
    str: ansistring;
begin
  readln(n);
  ans := -1;
  readln(str);
  for i := 1 to n do read(A[i]);
  for i := 1 to n-1 do
  begin
    if (str[i] = 'R') and (str[i+1] = 'L') then if ans = -1 then ans := (A[i+1]-A[i]) div 2 else ans := min(ans,(A[i+1]-A[i]) div 2);
  end;
  write(ans);
end.