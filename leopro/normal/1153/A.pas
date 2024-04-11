uses
Math;

var
  n, t, i, m: Int32;
  s, d, first: array [1..100] of Int32;
  
begin
  ReadLn(n, t);
  for i := 1 to n do Readln(s[i], d[i]);
  ReadLn;
  for i := 1 to n do
  begin
    if s[i] >= t then first[i] := s[i] else first[i] := ceil((t - s[i]) / d[i]) * d[i] + s[i]; 
  end;
  m := first[1];
  for i := 1 to n do
  begin
    if m > first[i] then m := first[i];
  end;
  for i := 1 to n do
  begin
    if m = first[i] then begin writeln(i); exit; end;
  end;
end.