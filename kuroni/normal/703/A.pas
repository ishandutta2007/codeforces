uses math;
var a, b, t, k, n, i: longint;
begin
  read(n);
  for i := 1 to n do
  begin
    read(a,b);
    if a > b then inc(t);
    if a < b then inc(k);
  end;
  if t > k then write('Mishka');
  if t < k then write('Chris');
  if t = k then write('Friendship is magic!^^');
end.