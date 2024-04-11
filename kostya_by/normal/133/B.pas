program project1;

const cnt : array[1..8] of string = ('1000','1001','1010','1011','1100','1101','1110','1111');
      zn = '><+-.,[]';

var
   st, s : ansistring;
   i,j,k,n,m,ans,pt : longint;
begin
     ans:=0;
     read(st);
     s:='';
     for i:=1 to length(st) do s:=s + cnt[pos(st[i], zn)];
     //writeln(s);
     n:=length(st) * 4;
     pt:=1;
     for i:=n downto 1 do begin
         ans:=ans + pt * (ord(s[i]) - ord('0'));
         //writeln(ans);
         pt:=pt * 2;
         ans:=ans mod 1000003;
         pt:=pt mod 1000003;
     end;
     writeln(ans);
end.