program p1;

var
        nums : array[0..9] of string;
        i,j,k,n,m : longint;
        num,now : string;
begin
        readln(num);
        for i:=0 to 9 do readln(nums[i]);
        for i:=1 to 8 do begin
                now:=copy(num,1,10);
                for j:=0 to 9 do if now = nums[j] then write(j);
                delete(num,1,10);
        end;
end.