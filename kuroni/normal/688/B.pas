var str, temp, ans: ansistring;
    i: longint;

begin
  readln(str);
  for i := 1 to length(str) do temp := temp + str[length(str)+1-i];
  ans := str + temp;
  write(ans);
end.