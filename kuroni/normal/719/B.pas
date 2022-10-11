uses math;
var str, chk1, chk2: ansistring;
    i, n, ans, chan, le: longint;
begin
  readln(n);
  readln(str);
  for i := 1 to n do if i mod 2 = 1 then
  begin
    chk1 := chk1 + 'r';
    chk2 := chk2 + 'b';
  end
  else
  begin
    chk1 := chk1 + 'b';
    chk2 := chk2 + 'r';
  end;
  chan := 0; le := 0;
  for i := 1 to n do if chk1[i] <> str[i] then
    if i mod 2 = 0 then inc(chan) else inc(le);
  ans := max(chan,le);
  chan := 0; le := 0;
  for i := 1 to n do if chk2[i] <> str[i] then
    if i mod 2 = 0 then inc(chan) else inc(le);
  ans := min(ans, max(chan,le));
  write(ans);
  readln;
  readln;
end.