uses math;
var n, i: longint;
    ans: ansistring;
begin
  ans := 'it';
  read(n);
  for i := 1 to n do
  begin
    if (n mod 2 = 1) then if (i mod 2 = 0) then ans := 'that I love ' + ans else ans := 'that I hate ' + ans;
    if (n mod 2 = 0) then if (i mod 2 = 1) then ans := 'that I love ' + ans else ans := 'that I hate ' + ans;
  end;
  ans := copy(ans,6,length(ans)-5);
  write(ans);
end.